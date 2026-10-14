void __fastcall cv_emit_function_debug_info(c2_fe_symbol *s)

{
  uint uVar1;
  uint32_t end_record;
  
  if (((s != (c2_fe_symbol *)0x0) && (s->cls == '\x04')) &&
     ((uVar1 = s->storage & 0xf0, uVar1 == 0x50 || (uVar1 == 0x30)))) {
    end_record = 0x10753731;
    cv_emit_proc_record(s);
    if ((g_opt_edit_and_continue != 0) || (g_opt_ZX != 0)) {
      end_record = 0x1077d94d;
      cv_emit_frame_proc_record(s);
    }
    g_cv_scope_cursor = g_cur_function->cv_scopes;
    end_record = 0x10753760;
    cv_emit_scope_symbols(s);
    end_record = 0x60002;
    (*g_hook_pad_section)(g_debug_symbols_section);
    (*g_writer_write_bytes_hook)(&end_record,4);
    g_debug_symbols_section->offset = g_debug_symbols_section->offset + 4;
    return;
  }
  end_record = 0x1077d941;
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",0x33d);
}

