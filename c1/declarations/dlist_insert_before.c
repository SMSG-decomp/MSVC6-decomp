int * __thiscall dlist_insert_before(void *this,int *iter,int *pos,int *value)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)pos[2];
  piVar1 = arena_alloc(g_arenas + 3,0xc);
  piVar2 = pos;
  if (pos == (int *)0x0) {
    piVar2 = piVar1;
  }
  piVar1[1] = (int)piVar2;
  if (piVar3 == (int *)0x0) {
    piVar3 = piVar1;
  }
  piVar1[2] = (int)piVar3;
  pos[2] = (int)piVar1;
  *(int **)(piVar1[2] + 4) = piVar1;
  *piVar1 = *value;
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  *iter = (int)piVar1;
  return iter;
}

