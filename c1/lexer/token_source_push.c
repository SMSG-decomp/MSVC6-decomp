void __thiscall token_source_push(int *stack,int stream,int arena,int kind,int on_pop,int *position)

{
  int *piVar1;
  int *piVar2;
  fe_arena *a;
  
  if (arena == 7) {
    arena = *(int *)(stream + 0x30);
  }
  a = g_arenas + arena;
  piVar1 = (int *)a->cur;
  piVar2 = (int *)g_arenas[arena].end;
  a->cur = (uchar *)(piVar1 + 5);
  if (piVar2 < piVar1 + 5) {
    arena_grow(a);
  }
  if (piVar1 != (int *)0x0) {
    piVar1[1] = stack[1];
    *piVar1 = stream;
    piVar1[2] = *position;
    piVar1[3] = kind;
    piVar1[4] = on_pop;
    stack[1] = (int)piVar1;
    g_token_position = *(int *)(stream + 4);
    return;
  }
  stack[1] = 0;
  g_token_position = *(int *)(stream + 4);
  return;
}

