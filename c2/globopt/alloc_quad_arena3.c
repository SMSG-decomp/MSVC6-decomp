void * __fastcall alloc_quad_arena3(int a,int b,int c,int d)

{
  int *piVar1;
  
  piVar1 = arena_alloc(3,0x14);
  *piVar1 = a;
  piVar1[1] = b;
  piVar1[2] = c;
  piVar1[3] = d;
  return piVar1;
}

