void __cdecl pragma_pack_push(int value,int ident)

{
  int *piVar1;
  
  if (value == 0) {
    value = g_pack_stack->top->packing;
  }
  piVar1 = list_alloc_cell((int *)g_pack_stack);
  piVar1[1] = value;
  piVar1[2] = ident;
  return;
}

