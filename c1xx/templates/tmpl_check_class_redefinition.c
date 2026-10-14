void __cdecl tmpl_check_class_redefinition(c1xx_token_stream *value,int key)

{
  byte bVar1;
  
  if ((*(byte *)(key + 3) & 4) == 0) {
    bVar1 = *(byte *)(*(int *)(key + 0x24) + 0x3e);
    if ((bVar1 & 8) != 0) {
      *(byte *)(key + 3) = *(byte *)(key + 3) | 4;
      diag_error(0x3b9,key);
      return;
    }
    *(byte *)(*(int *)(key + 0x24) + 0x3e) = bVar1 | 8;
    tmpl_set_definition_tokens(value,(c1_symbol *)key);
  }
  return;
}

