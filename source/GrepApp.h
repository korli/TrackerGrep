/*
 * Copyright (c) 1998-2007 Matthijs Hollemans
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 */
 
#include <Application.h>
#include <MessageRunner.h>

#define APP_SIGNATURE "application/x-vnd.mahlzeit.trackergrep"

#ifndef __GREP_APP_H__
#define __GREP_APP_H__

class GrepApp : public BApplication {
	public:
		GrepApp();
		~GrepApp();

		virtual void ArgvReceived(int32 argc, char **argv);
		virtual void RefsReceived(BMessage *message);
		virtual void MessageReceived(BMessage *message);
		virtual void ReadyToRun();

	private:

		void TryQuit();
		void NewUnfocusedGrepWindow();
			
		bool fGotArgvOnStartup;
		bool fGotRefsOnStartup;
		
		BMessageRunner *fQuitter;
};

#endif	// __GREP_APP_H__
