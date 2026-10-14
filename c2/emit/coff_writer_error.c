void __fastcall coff_writer_error(uint32_t code,char *file,int line)

{
  char *message;
  char *file_name;
  
  if (code != 0xe) {
    g_error_count = g_error_count + 1;
    fatal_error(1,"E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x6d9);
  }
  file_name = g_opt_object_path;
  message = load_message(0x136);
  fatal_error_errno(0x55,message,file_name);
}

