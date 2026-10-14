c1_node * __cdecl class_layout_vtable_this(void)

{
  c1_node *pcVar1;
  
  pcVar1 = expr_this_pointer((c1_symbol *)0x0);
  pcVar1 = class_build_vbtable_pointer_test(pcVar1);
  return pcVar1;
}

