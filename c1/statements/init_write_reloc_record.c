void __cdecl init_write_reloc_record(int kind,int value,int length)

{
  int local_c;
  int local_8;
  int local_4;
  
  local_c = kind;
  local_4 = value;
  local_8 = length;
  buffer_chain_append_bytes(&local_c,0xc,1,g_pch_record_list);
  return;
}

