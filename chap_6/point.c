struct point {
  int x;
  int y;
}

struct rect {
  struct point pt1;
  struct point pt2;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
  struct point temp;
  
  temp.x = x;
  temp.y = y; 
  return temp;
}

struct rect screen;
struct point middle'
struct point makepoint(int,int);

screen.pt1 = makepoint(0,0);
screen.pt2 = makepoint(XMAX,YMAX);
middle = makepoint((screen.pt1.x + screen.pt2.x)/2,(screen.pt1.y + screen.pt2,y)/2);

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

/* ptinrect: return 1 if p in r, 0 if not (top and right not included) */
int ptinrect(struct point p, struct rect r)
{
  return p.x >= rect.pt1.x && p.x < rect.pt2.x
      && p.y >= rect.pt1.y && p.y < rect.pt2.y;
}

# define min(a, b) ((a) < (b) ? (a) : (b))
# define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect: canonicalize coordinates of a rectangle */\
struct rect(struct rect r)
{
  struct rect temp;
  
  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}

struct point *pp;

struct point origin, *pp;

pp = &origin;
printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);

printf("origin is (%d,%d)\n", pp->x, pp->y);

struct rect r, *rp = &r;

r.pt1.x;
rp->pt1.x;
(r.pt1).x;
(rp->pt1).x;
