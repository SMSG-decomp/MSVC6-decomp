void __fastcall coff_function_checksum_add(void *pb,uint32_t cb)

{
  uint32_t sig;
  
  if (g_coff_current_section == (c2_coff_section *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xa29);
  }
  sig = SigForPbCb(pb,cb,g_coff_current_section->fn_signature);
  g_coff_current_section->fn_signature = sig;
  return;
}

