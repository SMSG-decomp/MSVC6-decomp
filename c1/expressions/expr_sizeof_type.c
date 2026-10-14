c1_node * __cdecl expr_sizeof_type(c1_type *type)

{
  int value;
  c1_node *pcVar1;
  
  value = type_size(type);
  if (value == 0) {
    if (g_opt_Zg != '\0') {
      return (c1_node *)0x0;
    }
    if ((type->code & 0x200) == 0) {
      diag_warning(1,0x22);
    }
    else {
      diag_error(0x1b,(type->extra).sym);
    }
  }
  pcVar1 = tree_new_int_constant(value);
  pcVar1->type = g_type_unsigned_int;
  pcVar1->op = 'e';
  return pcVar1;
}

