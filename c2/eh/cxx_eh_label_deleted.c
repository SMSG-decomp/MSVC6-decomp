void __fastcall cxx_eh_label_deleted(c2_fe_symbol *label)

{
  c2_tuple *t;
  uint uVar1;
  uint all_done;
  c2_eh_state *object;
  c2_cxx_catch *catch_rec;
  c2_cxx_try_block *object_try;
  
  all_done = 1;
  object = g_eh_object_records;
  if (g_eh_object_records != (c2_eh_state *)0x0) {
    do {
      uVar1 = object->flags;
      if (((char)uVar1 == '\x06') &&
         (object_try = (object->u1c).try_block, object_try != (c2_cxx_try_block *)0x0)) {
        for (catch_rec = object_try->catches; catch_rec != (c2_cxx_catch *)0x0;
            catch_rec = catch_rec->next) {
          if (catch_rec->label == label) {
            if (catch_rec != (c2_cxx_catch *)0x0) {
              if ((uVar1 & 0x400) == 0) {
                t = object_try->begin_tuple;
                object->flags = uVar1 | 0x400;
                if (t != (c2_tuple *)0x0) {
                  tuple_unlink_free(t);
                }
              }
              goto LAB_107893fb;
            }
            break;
          }
        }
        all_done = all_done & uVar1 >> 10 & 1;
      }
LAB_107893fb:
      object = object->next;
    } while (object != (c2_eh_state *)0x0);
    if (all_done == 0) {
      return;
    }
  }
  all_done = g_cur_function->flags;
  g_cur_function->flags = all_done & 0xfffeffff;
  if ((all_done & 0x8000) == 0) {
    g_frame_eh_record = (c2_fe_symbol *)0x0;
    g_eh_record_pushed = 0;
  }
  return;
}

