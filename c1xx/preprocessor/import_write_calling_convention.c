void __cdecl import_write_calling_convention(c1_il_buffer *buf,int callconv)

{
  if (callconv == 1) {
    import_text_puts(buf,"__cdecl");
  }
  else {
    if (callconv == 2) {
      import_text_puts(buf,"__pascal");
      return;
    }
    if (callconv == 4) {
      import_text_puts(buf,"__stdcall");
      return;
    }
  }
  return;
}

