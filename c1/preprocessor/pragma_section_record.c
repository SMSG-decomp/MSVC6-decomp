void __cdecl pragma_section_record(int kind,int id,char *text)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = text;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  init_write_reloc_record(kind,id,~uVar2 & 0xffff);
  buffer_chain_append_bytes(text,~uVar2 & 0xffff,1,g_pch_record_list);
  return;
}

