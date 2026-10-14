int __cdecl decl_parse_linkage_specification(c1xx_decl_specifiers *spec,c1_node *string)

{
  char cVar1;
  char *pcVar2;
  c1_u8 cVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  if (((uint)string->right & 0x10000) != 0) {
    diag_error(2);
  }
  if (g_block_depth != '\0') {
    diag_error(0x256);
  }
  if ((spec->spec[0] & 7) == 1) {
    spec->spec[0] = spec->spec[0] & 0xf8 | 0x20;
  }
  cVar3 = decl_warn_unexpected_specifiers_1(spec);
  if (cVar3 != '\0') {
    diag_warning(1,0x1f6);
  }
  pcVar2 = string->left;
  if (*pcVar2 == 'C') {
    if (pcVar2[1] == '+') {
      if ((pcVar2[2] == '+') && (pcVar2[3] == '\0')) {
        return 1;
      }
    }
    else if (pcVar2[1] == '\0') {
      return 2;
    }
  }
  uVar4 = 0xffffffff;
  pcVar6 = pcVar2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar5 = ~uVar4 - 1;
  if (0x20 < iVar5) {
    if (0x23 < iVar5) {
      iVar5 = 0x23;
    }
    builtin_strncpy(pcVar2 + iVar5 + -3,"...",4);
  }
  diag_error(0x219,string->left);
  return 0;
}

