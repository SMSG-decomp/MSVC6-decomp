void cxx_eh_reset_function_state(void)

{
  int iVar1;
  c2_eh_state **bucket;
  
  bucket = g_eh_state_hash;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *bucket = (c2_eh_state *)0x0;
    bucket = bucket + 1;
  }
  g_cxx_eh_init_insert_point = (c2_tuple *)0x0;
  g_ehhandler_symbol = (c2_fe_symbol *)0x0;
  g_eh_return_object_record = (c2_eh_state *)0x0;
  g_eh_guard_words = (c2_eh_guard_word *)0x0;
  g_eh_state_counter = 0;
  g_eh_try_block_count = 0;
  g_eh_trymap_tail = (c2_cxx_try_block *)0x0;
  g_eh_trymap_list = (c2_cxx_try_block *)0x0;
  g_eh_object_records = (c2_eh_state *)0x0;
  g_eh_current_state = (c2_eh_state *)0x0;
  g_eh_object_move_pending = 0;
  g_eh_name_counter = 0;
  return;
}

