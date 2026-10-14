c1_node * __cdecl expr_report_const_lvalue(char is_const,c1_node *object,c1_node *node,byte mode)

{
  if ((char)object->type->code < '\0') {
    if (((mode & 1) != 0) && (is_const != '\0')) {
      diag_error(0xa6);
    }
    return node;
  }
  return (c1_node *)0x0;
}

