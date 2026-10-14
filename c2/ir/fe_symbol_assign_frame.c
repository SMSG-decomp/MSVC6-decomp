uint __fastcall fe_symbol_assign_frame(c2_fe_symbol *fs)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint32_t size;
  
  lVar2 = g_opt_il_size;
  if ((fs->cls != '\x01') || (uVar3 = fs->attrs, (uVar3 & 0x800) != 0)) {
    return 0;
  }
  uVar1 = fs->storage;
  size = fs->size;
  switch(uVar1 >> 4 & 7) {
  case 1:
    iVar4 = frame_alloc_local(size,g_default_stack_align);
    fs->offset = iVar4;
    fs->attrs = fs->attrs | 0x800;
    return size;
  case 2:
  case 4:
    switch(uVar1 >> 7 & 0xf) {
    case 1:
    case 4:
      break;
    case 2:
      goto switchD_10701431_caseD_2;
    case 3:
      if ((uVar3 & 0x200) == 0) {
        fs->storage = uVar1 & 0xffffffaf | 0x20;
        fs->attrs = fs->attrs | 0x800;
        return size;
      }
      fs->storage = uVar1 & 0xfffff8ff | 0x80;
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x435);
    }
    break;
  case 3:
    if ((g_param_cursor == 8) &&
       (((g_cur_func_sym->attrs & 2) != 0 ||
        (((g_cur_func_sym->attrs & 1) == 0 && (g_code_pointer_size == 6)))))) {
      g_param_cursor = 0xc;
    }
    iVar4 = (int)size % g_opt_il_size;
    fs->offset = g_param_cursor;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = lVar2 - iVar4;
    }
    size = size + iVar4;
    g_param_cursor = g_param_cursor + size;
switchD_10701431_caseD_2:
    fs->attrs = fs->attrs | 0x800;
    return size;
  case 5:
    if ((uVar3 & 0x20) == 0) {
      fs->attrs = fs->attrs | 0x800;
      return size;
    }
    break;
  case 6:
    uVar3 = uVar1 >> 7 & 0xf;
    if ((uVar3 != 1) && (uVar3 != 4)) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x414);
    }
    break;
  case 7:
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x44d);
  }
  data_symbol_align_and_place(fs);
  fs->attrs = fs->attrs | 0x800;
  return size;
}

