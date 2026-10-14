void coff_check_extended_relocs(void)

{
  int *piVar1;
  
  piVar1 = coff_list_next(g_coff_sections);
  while (piVar1 != (int *)0x0) {
    if (0xfffe < *(uint *)(*piVar1 + 0x34)) {
      g_incr_object_not_reusable = 1;
    }
    if ((*(ushort *)((int)piVar1 + 0x12) & 2) != 0) {
      g_coff_header_section_count._2_2_ = g_coff_header_section_count._2_2_ + -1;
      *(ushort *)((int)piVar1 + 0x12) = *(ushort *)((int)piVar1 + 0x12) & 0xfffd;
    }
    piVar1 = coff_list_next(g_coff_sections);
  }
  return;
}

