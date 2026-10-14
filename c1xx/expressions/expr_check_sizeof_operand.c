c1_node * expr_check_sizeof_operand(c1_type *type)

{
  c1_type *t;
  int value;
  c1_node *pcVar1;
  
  t = type->base;
  value = type_size(t);
  if (value == 0) {
    if (g_opt_Zg != '\0') {
      return (c1_node *)0x0;
    }
    if ((t->code & 0x200) == 0) {
      diag_error(0x46);
    }
    else if ((((((t->extra).cls)->detail).cls)->flags3f & 0x80) == 0) {
      diag_error(0x1b,(t->extra).cls);
    }
  }
  pcVar1 = tree_new_int_constant(value);
  pcVar1->type = g_type_unsigned_int;
  pcVar1->op = 'e';
  return pcVar1;
}

