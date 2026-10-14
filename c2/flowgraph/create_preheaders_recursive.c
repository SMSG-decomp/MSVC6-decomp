uint32_t __fastcall create_preheaders_recursive(c2_loop *loop,c2_function *fn)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (; loop != (c2_loop *)0x0; loop = loop->next) {
    uVar1 = create_preheaders_recursive(loop->inner,fn);
    uVar2 = loop_ensure_preheader(loop,fn);
    uVar3 = uVar3 | uVar1 | uVar2;
  }
  return uVar3;
}

