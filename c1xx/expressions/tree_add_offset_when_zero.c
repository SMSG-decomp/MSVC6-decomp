c1_node * __cdecl tree_add_offset_when_zero(c1_node *test,c1_node *base,int value)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *left;
  c1_type *pcVar3;
  
  if (value == 0) {
    return base;
  }
  pcVar3 = g_type_int;
  pcVar1 = tree_new_int_constant(0);
  pcVar1 = tree_new_node(';',test,pcVar1,pcVar3);
  pcVar2 = tree_new_int_constant(0);
  left = tree_new_int_constant(value);
  pcVar2 = tree_new_binary('6',left,pcVar2);
  pcVar1 = tree_new_binary_typed_right('V',pcVar1,pcVar2);
  pcVar3 = type_int();
  pcVar1 = tree_new_node('Q',base,pcVar1,pcVar3);
  return pcVar1;
}

