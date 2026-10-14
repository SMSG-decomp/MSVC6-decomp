uint32_t __fastcall invert_loops_recursive(c2_loop *loop,c2_function *fn)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (; loop != (c2_loop *)0x0; loop = loop->next) {
    uVar1 = invert_loops_recursive(loop->inner,fn);
    uVar2 = invert_loop(loop,fn);
    uVar3 = uVar3 | uVar1 | uVar2;
  }
  return uVar3;
}

