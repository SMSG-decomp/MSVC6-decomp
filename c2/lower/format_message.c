char * __fastcall format_message(UINT id)

{
  char *pcVar1;
  
  load_message_prefixes();
  pcVar1 = load_string_resource(id,g_message_text,0x180);
  return pcVar1;
}

