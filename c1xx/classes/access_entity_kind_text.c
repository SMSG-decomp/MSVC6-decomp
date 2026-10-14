char * __cdecl access_entity_kind_text(byte *sym)

{
  char cVar1;
  ushort *puVar2;
  byte bVar3;
  char *pcVar4;
  
  bVar3 = *sym & 0x1f;
  if (bVar3 == 4) {
    puVar2 = *(ushort **)(sym + 0x14);
    cVar1 = (char)*puVar2;
    while (cVar1 < '\0') {
      puVar2 = *(ushort **)(puVar2 + 2);
      cVar1 = (char)*puVar2;
    }
    pcVar4 = type_keyword_text(*puVar2);
    return pcVar4;
  }
  if (bVar3 != 5) {
    if ((bVar3 == 10) && ((sym[0x20] & 7) == 7)) {
      return "typedef";
    }
    pcVar4 = misc_string_get(0x14e);
    return pcVar4;
  }
  pcVar4 = misc_string_get(0x14f);
  return pcVar4;
}

