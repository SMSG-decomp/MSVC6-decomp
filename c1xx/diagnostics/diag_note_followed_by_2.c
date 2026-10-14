void __fastcall diag_note_followed_by_2(c1_conversion *conv)

{
  diag_note_conversion_record(conv->first);
  diag_note(0x1838);
  diag_note(conv->note);
  return;
}

