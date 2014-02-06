#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct nlist {         /*table entry: a linked list */
  struct nlist *next;  /* next entry in the chain */
  char *name;          /* defined name */
  char *defn;          /* replacement name */
};

# define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];  /* pointer table */

/* hash: form has value for string */
unsigned hash(char *s)
{
  unsigned hashval;
  
  for(hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *);
char *strdup(char *);

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
  struct nlist *np;
  
  for( np = hashtab[hash(s)]; np != NULL; np = np->next)
    if(strcmp(s,np->name) == 0)
      return np;  /* found */
  return NULL;  /* not found */
}



/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;
  
  if((np = lookup(name)) == NULL) { /* not found */
    np = (struct nlist *) malloc(sizeof(*np));
    if( np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;  /* allocation failed */
    hashval = hash(name);
    np->next = hashtab[hashval];  /* insert at front of list */
    hashtab[hashval] = np;
  } else  /* already there */
    free((void *) np->defn);  /* free previous defn */
  if((np->defn = strdup(defn)) == NULL)
    return NULL;  /* allocation failed */
  return np;
}

/* undef: remove a name from hashtab, return 1 if deleted, 0 if not found */
int undef(char *s)
{
  struct nlist *np, *nprev;
  
  nprev = NULL;
  
  for(np = hashtab[hash(s)]; np != NULL; np = np->next) {
    if(strcmp(s,np->name) == 0) { /* the entry that should be deleted */
      if(nprev == NULL)  /* pathological case of first entry */
        hashtab[hash(s)] = np->next;  /* put it first in the list */
      else
        nprev->next = np->next;  /* link to next entry */
      free( (void *) np );       /* free the memory that was used for the entry */ 
      return 1;
    }  else
         nprev = np;  /* previous entry is now this one and continue the loop */
  }
  return 0;  /* entry s wasn't in the loop to begin with */
}

/* printhtab:  print the hashtab as word, definition pairs */
void printhtab(void)
{
  int h;
  struct nlist *np;
  
  for(h = 0; h < HASHSIZE; h++)
    for(np = hashtab[h]; np != NULL; np = np->next)
      if(np->name != NULL && np->defn != NULL)
        printf("%s, %s\n",np->name,np->defn);
      else
        printf("NULL pointer in hashtab[%d]\n",h);
}

main()
{
  struct nlist *np;
  
  if( (np = install("pet","dog")) != NULL)
    printf("added: pet, dog\n");
  else
    printf("FAIL\n");
  if( (np = install("enemy","cat")) != NULL)
    printf("added: enemy, cat\n");
  else
    printf("FAIL\n");
  printhtab();
  undef("enemy");
  printf("undefined: enemy\n");
  printhtab();


}