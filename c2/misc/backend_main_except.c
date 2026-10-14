void backend_main_except(void)

{
  uint32_t ice_line;
  int unaff_EBP;
  int saved_esp;
  
  saved_esp = *(int *)(unaff_EBP + -0x18);
  if (*(int *)(unaff_EBP + -0x1c) == -0x3ffffffb) {
    ice_line = 0x1ee;
  }
  else {
    if (*(int *)(unaff_EBP + -0x1c) == -0x3fffff03) {
      *(undefined4 *)(saved_esp + -4) = 0x3f;
      *(undefined4 *)(saved_esp + -8) = 0x1077d4b9;
      fatal_error(*(int *)(saved_esp + -4));
    }
    ice_line = 0x1fa;
  }
  *(uint32_t *)(saved_esp + -4) = ice_line;
  g_error_count = g_error_count + 1;
  *(char **)(saved_esp + -8) = "E:\\8168\\vc98\\p2\\src\\P2\\main.c";
  *(undefined4 *)(saved_esp + -0xc) = 1;
  *(undefined4 *)(saved_esp + -0x10) = 0x1076a8fe;
  fatal_error(*(int *)(saved_esp + -0xc));
}

