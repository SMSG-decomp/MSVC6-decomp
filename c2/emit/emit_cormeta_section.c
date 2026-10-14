void emit_cormeta_section(void)

{
  FILE *_File;
  uint32_t number;
  c2_fe_symbol *sec;
  size_t cb;
  uint8_t chunk_buf [1024];
  
  _File = open_il_file(g_opt_il_path,"md","rb","COR meta data il");
  number = fe_symbol_next_id();
  sec = section_symbol_new(0x107a90b4,0x107a90c0,number);
  section_set_defaults(sec);
  sec->level = '\0';
  (sec->u44).section_class = '\x1a';
  (sec->u3e).label_flags = 8;
  coff_pad_section_to_offset(sec);
  do {
    cb = fread(chunk_buf,1,0x400,_File);
    if (cb != 0) {
      coff_write_bytes(chunk_buf,cb);
    }
  } while (cb == 0x400);
  return;
}

