void __cdecl pragma_message_text(void *list,char *format,...)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char local_400 [1024];
  
  format_vsnprintf(local_400,format,0x400,&stack0x0000000c);
  uVar2 = 0xffffffff;
  pcVar3 = local_400;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  buffer_chain_append_bytes(local_400,~uVar2 - 1,1,list);
  return;
}

