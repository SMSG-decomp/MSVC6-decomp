int __cdecl file_read_source_block(void *buffer)

{
  int iVar1;
  
  if (g_input_file->handle != -2) {
    iVar1 = _read(g_source_handle,buffer,0x7000);
    return iVar1;
  }
  iVar1 = mem_chain_read(g_injected_text_list,buffer,0x7000);
  return iVar1;
}

