int invoke_compiler_pass_except(void)

{
  int unaff_EBP;
  int exit_code;
  
  if (*(int *)(**(int **)(unaff_EBP + -0x20) + 0x10) != 1) {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4) = 0x1077d2b7;
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\dll.c",0x88);
  }
  exit_code = *(int *)(**(int **)(unaff_EBP + -0x20) + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return exit_code;
}

