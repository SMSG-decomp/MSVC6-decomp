c1_node * __cdecl expr_this_plus_offset(int sym2,int qualifiers,int value)

{
  c1_type *type;
  c1_node *pcVar1;
  c1_node *left;
  
  type = type_this_pointer((c1_symbol *)sym2,(c1_u16)qualifiers,0);
  pcVar1 = tree_new_int_constant(value);
  left = expr_this_pointer((c1_symbol *)0x0);
  pcVar1 = tree_new_node('S',left,pcVar1,type);
  return pcVar1;
}

