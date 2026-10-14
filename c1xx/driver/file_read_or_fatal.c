int __cdecl file_read_or_fatal(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *dst;
  char *buffer;
  
  buffer = (char *)g_input_file->buffer;
  if ((int)g_input_ptr - (int)buffer < g_input_file->last_read) {
    if (g_input_ptr[-1] == 0x1a) {
      g_input_ptr = g_input_ptr + -1;
      return 1;
    }
  }
  else {
    g_input_ptr = g_input_ptr + -1;
    (**(code **)(*g_source_tracker + 8))();
    iVar2 = 1;
    dst = buffer;
    do {
      dst = dst + -1;
      iVar1 = -iVar2;
      iVar2 = iVar2 + 1;
      *dst = g_input_ptr[iVar1];
    } while (iVar2 < 3);
    g_input_ptr = (byte *)buffer;
    (**(code **)(*g_source_tracker + 0xc))();
    if ((g_input_file->flags & 1) != 0) {
      *buffer = 0;
      g_input_file->last_read = 0;
      if ((g_input_file->flags & 4) == 0) {
        (**(code **)(*g_source_tracker + 0x14))(buffer,1);
        g_input_file->flags = g_input_file->flags | 4;
      }
      return 1;
    }
    uVar3 = file_read_source_block(buffer);
    g_input_file->block_offset = g_input_file->block_offset + g_input_file->last_read;
    g_input_file->last_read = uVar3;
    if (0 < (int)uVar3) {
      if ((((uVar3 < 0x7000) &&
           (g_input_file->flags = g_input_file->flags | 1, g_ms_extensions != '\0')) &&
          (g_input_file->handle != -2)) && (buffer[uVar3 - 1] != 10)) {
        buffer[uVar3] = 10;
        uVar3 = uVar3 + 1;
        g_input_file->last_read = uVar3;
      }
      buffer[uVar3] = 0;
      return 0;
    }
    if ((int)uVar3 < 0) {
      diag_fatal_file_errno
                (0x54,(-(uint)(g_include_depth != 0) & 2) + 0x155,g_input_file->file->name->text);
    }
    g_input_file->flags = g_input_file->flags | 1;
    if (g_ms_extensions != '\0') {
      *buffer = 10;
      buffer = buffer + 1;
    }
    *buffer = 0;
  }
  return 0;
}

