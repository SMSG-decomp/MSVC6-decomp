uint32_t __fastcall compact_loops_recursive(c2_loop *loop2,c2_function *fn)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (; loop2 != (c2_loop *)0x0; loop2 = loop2->next) {
    uVar1 = compact_loops_recursive(loop2->inner,fn);
    uVar2 = compact_loop_body(loop2,fn);
    uVar3 = uVar3 | uVar1 | uVar2;
  }
  return uVar3;
}

