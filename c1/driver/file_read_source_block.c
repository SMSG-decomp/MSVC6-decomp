int __cdecl file_read_source_block(void *buf)

{
  int iVar1;
  
  if (g_input_file->handle != -2) {
    iVar1 = _read(g_source_handle,buf,0x7000);
    return iVar1;
  }
  iVar1 = mem_chain_read(g_injected_text_list,buf,0x7000);
  return iVar1;
}

