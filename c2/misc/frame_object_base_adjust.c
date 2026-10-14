int __fastcall frame_object_base_adjust(c2_symbol *obj)

{
  uint8_t uVar1;
  uint uVar2;
  
  uVar1 = obj->cls;
  if (uVar1 == '\x05') {
    if (((byte)obj->storage->fe->storage & 0x70) != 0x30) {
      return 0;
    }
    if (g_opt_favor_speed != 0) {
      return 4;
    }
    uVar2 = g_cur_function->flags;
  }
  else if (((obj->storage->u28).frame_home < 1) || (uVar1 != '\x03')) {
    if (uVar1 != '\x04') {
      return 0;
    }
    if (obj->storage->fe->offset < 1) {
      return 0;
    }
    if (g_opt_favor_speed != 0) {
      return 4;
    }
    uVar2 = g_cur_function->flags;
  }
  else {
    if (g_opt_favor_speed != 0) {
      return 4;
    }
    uVar2 = g_cur_function->flags;
  }
  if ((uVar2 & 0x18000) != 0) {
    return 0;
  }
  return 4;
}

