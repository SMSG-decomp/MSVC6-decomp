void __fastcall diag_note_conversion_record(c1_conversion *conv)

{
  if (conv->note_fn != (code *)0x0) {
    (*conv->note_fn)();
    return;
  }
  diag_note(conv->note);
  return;
}

