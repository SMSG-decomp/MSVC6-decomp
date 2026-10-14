c1_node * __cdecl expr_spill_and_comma(c1_node *e)

{
  c1_node *pcVar1;
  c1_type *pcVar2;
  
  pcVar1 = expr_spill_to_temporary(&e);
  pcVar1 = tree_new_binary_typed_right('7',e,pcVar1);
  if ((pcVar1->type->code & 0x8f) == 0x83) {
    pcVar2 = conv_array_to_pointer_type(pcVar1);
    pcVar1->type = pcVar2;
  }
  return pcVar1;
}

