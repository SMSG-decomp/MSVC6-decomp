void __cdecl pragma_pack_push(int value,int ident)

{
  c1_pack_cell *pcVar1;
  
  if (value == 0) {
    value = g_pack_stack->top->packing;
  }
  pcVar1 = list_alloc_cell(g_pack_stack);
  pcVar1->packing = value;
  pcVar1->ident = (void *)ident;
  return;
}

