void __fastcall pch_relocate_token(c1_token *token)

{
  char cVar1;
  c1_type *type;
  
  switch(token->code) {
  case '\x06':
  case '\a':
    pch_relocate_slot_once(&g_pch_image,(uint)&token->value);
    break;
  case '\"':
  case '#':
  case '$':
    pch_relocate_slot_once(&g_pch_image,(uint)((int)&token->value + 4));
    pch_relocate_slot_once(&g_pch_image,(uint)((int)&token->value + 0xc));
    pch_relocate_slot_once(&g_pch_image,(uint)((int)&token->value + 0x10));
    return;
  case 'e':
    pch_relocate_slot_once(&g_pch_image,(uint)&token->value);
    type = (token->value).constant.type;
    cVar1 = (char)type->code;
    while (cVar1 < '\0') {
      type = type->base;
      cVar1 = (char)type->code;
    }
    if ((type->code & 0x20) != 0) {
      pch_relocate_slot_once(&g_pch_image,(uint)((int)&token->value + 8));
      return;
    }
  }
  return;
}

