void __fastcall coff_set_section_count_and_seek(uint16_t requested)

{
  uint32_t uVar1;
  uint uVar2;
  
  if ((short)g_coff_header_section_count != 0) {
    return;
  }
  if (requested == 0) {
    uVar2 = (uint)(ushort)g_coff_section_order->count;
  }
  else {
    uVar1 = coff_list_count(g_coff_sections);
    if (requested < uVar1) {
      (*g_coff_error_fn)(7,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x3d8);
      goto LAB_107596f3;
    }
    uVar1 = coff_list_count(g_coff_sections);
    uVar2 = (g_coff_section_order->count + (uint)requested) - uVar1;
    if (0xffff < uVar2) {
      (*g_coff_error_fn)(6,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x3e1);
      goto LAB_107596f3;
    }
  }
  g_coff_header_section_count = CONCAT22(g_coff_header_section_count._2_2_,(short)uVar2);
LAB_107596f3:
  fseek(g_coff_object_file,(g_coff_header_section_count & 0xffff) * 0x28 + 0x14,0);
  return;
}

