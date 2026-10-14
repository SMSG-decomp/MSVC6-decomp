bool __cdecl guid_parse_string(char *text,c1_guid *guid)

{
  char cVar1;
  wchar_t *lpsz;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char local_84;
  undefined4 local_83;
  
  uVar3 = 0xffffffff;
  pcVar6 = text;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  uVar4 = uVar3 - 1;
  if (uVar4 < 0x81) {
    if (*text != '{') {
      local_84 = '{';
      pcVar6 = (char *)&local_83;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)text;
        text = text + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = *text;
        text = text + 1;
        pcVar6 = pcVar6 + 1;
      }
      (&local_84)[uVar3] = '}';
      *(undefined1 *)((int)&local_83 + uVar3) = 0;
      text = &local_84;
    }
    lpsz = multibyte_to_wide_arena(text);
    lVar2 = CLSIDFromString(lpsz,guid);
    return -1 < lVar2;
  }
  return false;
}

