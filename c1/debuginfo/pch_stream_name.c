char * __cdecl pch_stream_name(char *out,char *file,char *ext)

{
  char cVar1;
  byte *name;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  byte local_104;
  char local_103;
  byte local_102 [258];
  
  uVar3 = 0xffffffff;
  pcVar2 = g_pch_symbol_prefix;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  pcVar2 = g_pch_symbol_prefix;
  pcVar5 = out;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  builtin_strncpy(out + uVar3,"@00@",4);
  file_make_canonical_path((char *)&local_104,file,0x104);
  name = local_102;
  if (local_103 != ':') {
    name = &local_104;
  }
  pcVar2 = name_encode_for_stream(out + uVar3 + 4,name);
  *pcVar2 = '@';
  pcVar2 = pcVar2 + 1;
  if (ext != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = ext;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar3 - 1;
    pcVar5 = pcVar2;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)ext;
      ext = ext + 4;
      pcVar5 = pcVar5 + 4;
    }
    pcVar2 = pcVar2 + uVar4;
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar5 = *ext;
      ext = ext + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  if (0xf7 < (int)pcVar2 - (int)out) {
    pcVar2 = out + 0xf7;
  }
  *pcVar2 = '\0';
  return pcVar2 + (1 - (int)out);
}

