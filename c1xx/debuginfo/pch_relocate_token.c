void __fastcall pch_relocate_token(c1_u8 *token)

{
  byte bVar1;
  byte *pbVar2;
  
  switch(*token) {
  case '\x06':
  case '\a':
  case 0x9f:
  case 0xc9:
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 8));
    return;
  case '\"':
  case '#':
  case '$':
  case 0x8f:
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 0xc));
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 0x20));
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 0x24));
    return;
  case 'e':
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 8));
    pbVar2 = *(byte **)(token + 8);
    bVar1 = *pbVar2;
    while ((char)bVar1 < '\0') {
      pbVar2 = *(byte **)(pbVar2 + 4);
      bVar1 = *pbVar2;
    }
    if ((*pbVar2 & 0x20) != 0) {
      pch_relocate_slot_once(&g_pch_image,(uint *)(token + 0x10));
      return;
    }
    break;
  case 0x8e:
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 0xc));
    break;
  case 0x96:
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 8));
    diag_fatal(1,"p1inl.inl",0x4a5);
  case 0x98:
  case 0xb0:
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 8));
    pch_relocate_tree(*(c1_node **)(token + 8));
    return;
  case 0xa7:
    diag_fatal(1,".\\Token_IO.cpp",0x228);
  case 0xca:
    pch_relocate_slot_once(&g_pch_image,(uint *)(token + 8));
    pch_relocate_template_header(*(uint *)(token + 8));
    return;
  }
  return;
}

