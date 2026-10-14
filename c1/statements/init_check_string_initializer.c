void __cdecl init_check_string_initializer(char kind,c1_type *type,c1_node *element,c1_node *init)

{
  char cVar1;
  bool bVar2;
  
  if (((init->op == '\a') && (kind < '\0')) && (-1 < (char)element->type->code)) {
    if (((uint)init->right & 0x10000) == 0) {
      cVar1 = (char)type->code;
      while (cVar1 < '\0') {
        type = type->base;
        cVar1 = (char)type->code;
      }
      bVar2 = type->code == 0x2012;
    }
    else {
      cVar1 = (char)type->code;
      while (cVar1 < '\0') {
        type = type->base;
        cVar1 = (char)type->code;
      }
      bVar2 = (type->code & 0xfff) == 0x11;
    }
    if (bVar2) {
      diag_error(0x35);
      return;
    }
  }
  diag_error(0x4b);
  return;
}

