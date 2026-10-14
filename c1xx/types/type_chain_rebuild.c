c1_type * __cdecl type_chain_rebuild(c1_type *type,void *keep,void *map,int arg)

{
  int iVar1;
  c1_type *pcVar2;
  c1_type cStack_10;
  
  if (type == (c1_type *)0x0) {
    return (c1_type *)0x0;
  }
  if (keep != (void *)0x0) {
    iVar1 = (*keep)(type);
    pcVar2 = type->base;
    if (iVar1 == 0) {
      pcVar2 = type_chain_rebuild(pcVar2,keep,map,arg);
    }
    if (map != (void *)0x0) {
      if (type->base != pcVar2) {
        cStack_10.code = type->code;
        cStack_10.flags = type->flags;
        cStack_10.extra = type->extra;
        cStack_10.debug_index = type->debug_index;
        cStack_10.base = pcVar2;
        type = type_intern(&cStack_10);
      }
      pcVar2 = (c1_type *)(*map)(type,arg);
      return pcVar2;
    }
    return type;
  }
  pcVar2 = (c1_type *)(*map)(type,arg);
  return pcVar2;
}

