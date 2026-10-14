void __thiscall conv_report_cannot_convert(c1_conversion *conv,char report)

{
  if ((conv->source->code != 0x80f) && (conv->target->code != 0x80f)) {
    if (report != '\0') {
      diag_begin_global(g_token_position);
      diag_error(0x1b8,(uint)conv->op,conv->source,conv->target);
    }
    if (conv->note_fn == (code *)0x0) {
      diag_note(conv->note);
    }
    else {
      (*conv->note_fn)();
    }
    if (report != '\0') {
      diag_end_global();
    }
  }
  return;
}

