int __cdecl init_is_char_array_string_init(c1_symbol *sym,c1_node *node)

{
  char cVar1;
  c1_type *pcVar2;
  
  if (node == (c1_node *)0x0) {
    return 0;
  }
  if (node->op != '\a') {
    return 0;
  }
  if ((sym->flags5 & 4) == 0) {
    return 0;
  }
  if (((char)sym->type->code < '\0') && (pcVar2 = sym->type->base, -1 < (char)pcVar2->code)) {
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    return (uint)((c1_u16)(pcVar2->code & 0xfff) ==
                 (c1_u16)((((uint)node->right & 0x10000) != 0) + 0x11));
  }
  return 0;
}

