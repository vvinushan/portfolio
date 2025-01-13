namespace CarInsuranceDataInterface
{
    partial class UC_Home
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.IntroLabel1 = new System.Windows.Forms.Label();
            this.IntroLabel2 = new System.Windows.Forms.Label();
            this.IntroLabel3 = new System.Windows.Forms.Label();
            this.IntroLabel4 = new System.Windows.Forms.Label();
            this.IntroLabel5 = new System.Windows.Forms.Label();
            this.HomeExitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // IntroLabel1
            // 
            this.IntroLabel1.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.IntroLabel1.AutoSize = true;
            this.IntroLabel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.IntroLabel1.Location = new System.Drawing.Point(104, 60);
            this.IntroLabel1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.IntroLabel1.Name = "IntroLabel1";
            this.IntroLabel1.Size = new System.Drawing.Size(1284, 31);
            this.IntroLabel1.TabIndex = 0;
            this.IntroLabel1.Text = "Use the tabs at the top of the page to navigate the interface connected to the da" +
    "tabase of your customers.";
            // 
            // IntroLabel2
            // 
            this.IntroLabel2.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.IntroLabel2.AutoSize = true;
            this.IntroLabel2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.IntroLabel2.Location = new System.Drawing.Point(287, 117);
            this.IntroLabel2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.IntroLabel2.Name = "IntroLabel2";
            this.IntroLabel2.Size = new System.Drawing.Size(975, 31);
            this.IntroLabel2.TabIndex = 1;
            this.IntroLabel2.Text = "To browse all customer data in order and modify/delete, click on ‘All Customers’." +
    "";
            // 
            // IntroLabel3
            // 
            this.IntroLabel3.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.IntroLabel3.AutoSize = true;
            this.IntroLabel3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.IntroLabel3.Location = new System.Drawing.Point(347, 175);
            this.IntroLabel3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.IntroLabel3.Name = "IntroLabel3";
            this.IntroLabel3.Size = new System.Drawing.Size(846, 31);
            this.IntroLabel3.TabIndex = 2;
            this.IntroLabel3.Text = "To add a new customer, click on ‘Add Customer’ and fill in the details.";
            // 
            // IntroLabel4
            // 
            this.IntroLabel4.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.IntroLabel4.AutoSize = true;
            this.IntroLabel4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.IntroLabel4.Location = new System.Drawing.Point(392, 234);
            this.IntroLabel4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.IntroLabel4.Name = "IntroLabel4";
            this.IntroLabel4.Size = new System.Drawing.Size(758, 31);
            this.IntroLabel4.TabIndex = 3;
            this.IntroLabel4.Text = "To search for a specific customer, click on ‘Search Customer’.";
            // 
            // IntroLabel5
            // 
            this.IntroLabel5.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.IntroLabel5.AutoSize = true;
            this.IntroLabel5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.IntroLabel5.Location = new System.Drawing.Point(483, 292);
            this.IntroLabel5.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.IntroLabel5.Name = "IntroLabel5";
            this.IntroLabel5.Size = new System.Drawing.Size(560, 31);
            this.IntroLabel5.TabIndex = 4;
            this.IntroLabel5.Text = "To exit the application, click the button below.";
            // 
            // HomeExitButton
            // 
            this.HomeExitButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.HomeExitButton.Location = new System.Drawing.Point(1189, 357);
            this.HomeExitButton.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.HomeExitButton.Name = "HomeExitButton";
            this.HomeExitButton.Size = new System.Drawing.Size(222, 64);
            this.HomeExitButton.TabIndex = 5;
            this.HomeExitButton.Text = "Exit Application";
            this.HomeExitButton.UseVisualStyleBackColor = true;
            this.HomeExitButton.Click += new System.EventHandler(this.HomeExitButton_Click);
            // 
            // UC_Home
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.HomeExitButton);
            this.Controls.Add(this.IntroLabel5);
            this.Controls.Add(this.IntroLabel4);
            this.Controls.Add(this.IntroLabel3);
            this.Controls.Add(this.IntroLabel2);
            this.Controls.Add(this.IntroLabel1);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "UC_Home";
            this.Size = new System.Drawing.Size(1492, 455);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label IntroLabel1;
        private System.Windows.Forms.Label IntroLabel2;
        private System.Windows.Forms.Label IntroLabel3;
        private System.Windows.Forms.Label IntroLabel4;
        private System.Windows.Forms.Label IntroLabel5;
        private System.Windows.Forms.Button HomeExitButton;
    }
}
