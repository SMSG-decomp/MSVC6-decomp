void __fastcall shift_auto_below_eh_record_cb(c2_fe_symbol *obj)

{
  if ((obj->cls == '\x01') && (((byte)obj->storage & 0x70) == 0x10)) {
    if (obj == g_frame_eh_record) {
      obj->offset = -obj->size;
      return;
    }
    obj->offset = obj->offset - g_frame_eh_record->size;
  }
  return;
}

