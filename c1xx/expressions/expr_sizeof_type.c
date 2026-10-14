c1_node * __cdecl expr_sizeof_type(c1_type *type)

{
  byte bVar1;
  int value;
  c1_node *pcVar2;
  
  bVar1 = (byte)type->code;
  if (((char)bVar1 < '\0') && ((bVar1 & 0x8f) == 0x80)) {
    pcVar2 = expr_check_sizeof_operand(type);
    return pcVar2;
  }
  value = type_size(type);
  if (value == 0) {
    if (g_opt_Zg != '\0') {
      return (c1_node *)0x0;
    }
    if ((type->code & 0x200) == 0) {
      diag_error(0x46);
    }
    else if ((((((type->extra).cls)->detail).cls)->flags3f & 0x80) == 0) {
      diag_error(0x1b,(type->extra).cls);
    }
  }
  pcVar2 = tree_new_int_constant(value);
  pcVar2->type = g_type_unsigned_int;
  pcVar2->op = 'e';
  return pcVar2;
}

