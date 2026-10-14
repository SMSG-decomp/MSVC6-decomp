void __fastcall
decl_scan_declarator_chain_reference_fragment(c1_type *chain_end,int rec,c1_type *layer)

{
  ushort flags;
  short n;
  int iVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  
code_r0x10483c73:
  n = 0x214;
LAB_10483c5b:
  diag_error(n,0x78);
  *(byte *)(rec + 0x3c) = *(byte *)(rec + 0x3c) | 1;
switchD_10401a9f_caseD_83:
  do {
    pcVar3 = layer;
    layer = pcVar3->base;
    if (layer == chain_end) {
      return;
    }
    flags = layer->flags & 7;
    if (flags != 0) goto LAB_10401a7d;
  } while ((layer->code & 0x83) != 0x81);
  if (layer != *(c1_type **)(rec + 4)) {
    pcVar2 = pcVar3;
    if ((pcVar3->code & 0x8f) == 0x83) {
      pcVar2 = type_skip_arrays(pcVar3->base);
    }
    if ((pcVar2->flags & 7) != 0) {
      if ((pcVar3->code & 0x8f) == 0x83) {
        pcVar3 = type_skip_arrays(pcVar3->base);
        flags = (byte)pcVar3->flags & 7;
      }
      else {
        flags = (byte)pcVar3->flags & 7;
      }
      goto LAB_10401a6b;
    }
    iVar1 = decl_default_calling_convention((void *)rec,(byte *)layer);
    flags = (ushort)iVar1;
    goto LAB_10401ac6;
  }
  flags = *(ushort *)(rec + 0xc) & 7;
  if (flags == 0) {
    *(byte *)(rec + 0x3c) = *(byte *)(rec + 0x3c) & 0xfd;
    iVar1 = decl_default_calling_convention((void *)rec,(byte *)layer);
    flags = (ushort)iVar1;
  }
  else {
    *(ushort *)(rec + 0xc) = *(ushort *)(rec + 0xc) & 0xfff8;
  }
  goto LAB_10401a6b;
LAB_10401a7d:
  layer->flags = layer->flags & 0xfff8;
  switch((byte)layer->code & 0x8f) {
  case 0x80:
    goto code_r0x10483c73;
  case 0x81:
  case 0x85:
    flags = decl_check_varargs_calling_convention((void *)rec,layer,flags);
    if (layer != *(c1_type **)(rec + 4)) {
LAB_10401ac6:
      pcVar3->flags = pcVar3->flags | flags;
    }
    break;
  case 0x82:
    goto switchD_10401a9f_caseD_82;
  default:
    goto switchD_10401a9f_caseD_83;
  case 0x84:
  case 0x86:
  case 0x8e:
    if (layer->base != chain_end) {
      flags = decl_check_varargs_calling_convention((void *)rec,layer->base,flags);
    }
    break;
  case 0x8a:
    n = 0x27d;
    goto LAB_10483c5b;
  }
LAB_10401a6b:
  layer->flags = layer->flags | flags;
  goto switchD_10401a9f_caseD_83;
switchD_10401a9f_caseD_82:
  n = 0xa5;
  goto LAB_10483c5b;
}

