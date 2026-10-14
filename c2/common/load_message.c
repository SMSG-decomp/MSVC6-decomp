char * __fastcall load_message(int id)

{
  char *pcVar1;
  
  load_message_prefixes();
  pcVar1 = find_message(id);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "";
  }
  return pcVar1;
}

