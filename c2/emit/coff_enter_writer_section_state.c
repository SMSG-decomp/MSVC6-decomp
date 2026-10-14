void __fastcall coff_enter_writer_section_state(void)

{
  if (g_coff_checksum_state == 0) {
    g_coff_checksum_state = 1;
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x9eb);
}

